# frozen_string_literal: true

require 'numo/narray'

require 'lbfgsb/version'
require 'lbfgsb/lbfgsbext'

module Lbfgsb
  module_function

  # Minimize a function using the L-BFGS-B algorithm.
  #
  # @param fnc [Method/Proc] Method for calculating the function to be minimized.
  # @param x_init [Numo::DFloat] (shape: [n_elements]) Initial point.
  # @param jcb [Method/Proc/Boolean] Method for calculating the gradient vector.
  #   If true is given, fnc is assumed to return the function value and gardient vector as [f, g] array.
  # @param args [Object] Arguments pass to the 'fnc' and 'jcb'.
  # @param bounds [Numo::DFloat/Nil] (shape: [n_elements, 2])
  #   \[lower, upper\] bounds for each element x. If nil is given, x is unbounded.
  # @param factr [Float] The iteration will be stop when
  #
  #   (f^k - f^\{k+1\})/max{|f^k|,|f^\{k+1\}|,1} <= factr * Lbfgsb::DBL_EPSILON
  #
  #   Typical values for factr: 1e12 for low accuracy; 1e7 for moderate accuracy; 1e1 for extremely high accuracy.
  # @param pgtol [Float] The iteration will be stop when
  #
  #   max{|pg_i| i = 1, ..., n} <= pgtol
  #
  #   where pg_i is the ith component of the projected gradient.
  # @param maxcor [Integer] The maximum number of variable metric corrections used to define the limited memory matrix.
  # @param maxiter [Integer] The maximum number of iterations.
  # @param verbose [Integer/Nil] If negative value or nil is given, no display output is generated.
  # @return [Hash] Optimization results; { x:, n_fev:, n_jev:, n_iter:, fnc:, jcb:, task:, success: }
  #   - x [Numo::DFloat] Updated vector by optimization.
  #   - n_fev [Interger] Number of calls of the objective function.
  #   - n_jev [Integer] Number of calls of the jacobian.
  #   - n_iter [Integer] Number of iterations.
  #   - fnc [Float] Value of the objective function.
  #   - jcb [Numo::Narray] Values of the jacobian
  #   - task [String] Description of the cause of the termination.
  #   - success [Boolean] Whether or not the optimization exited successfully.
  def minimize(fnc:, x_init:, jcb:, args: nil, bounds: nil, factr: 1e7, pgtol: 1e-5, maxcor: 10, maxiter: 15_000, verbose: nil)
    n_elements = x_init.size
    l = Numo::DFloat.zeros(n_elements)
    u = Numo::DFloat.zeros(n_elements)
    nbd = SZ_F77_INTEGER == 64 ? Numo::Int64.zeros(n_elements) : Numo::Int32.zeros(n_elements)

    unless bounds.nil?
      n_elements.times do |n|
        lower = bounds[n, 0]
        upper = bounds[n, 1]
        l[n] = lower
        u[n] = upper
        if lower.finite? && !upper.finite?
          nbd[n] = 1
        elsif lower.finite? && upper.finite?
          nbd[n] = 2
        elsif !lower.finite? && upper.finite?
          nbd[n] = 3
        end
      end
    end

    min_l_bfgs_b(fnc, x_init, jcb, args, l, u, nbd, maxcor, factr, pgtol, maxiter, verbose)
  end

  # @!visibility private
  def fnc(fnc, x, args)
    if args.is_a?(Hash)
      fnc.call(x, **args)
    elsif args.is_a?(Array)
      fnc.call(x, *args)
    elsif args.nil?
      fnc.call(x)
    else
      fnc.call(x, args)
    end
  end

  # @!visibility private
  def jcb(jcb, x, args)
    if args.is_a?(Hash)
      jcb.call(x, **args)
    elsif args.is_a?(Array)
      jcb.call(x, *args)
    elsif args.nil?
      jcb.call(x)
    else
      jcb.call(x, args)
    end
  end

  private_class_method :fnc, :jcb, :min_l_bfgs_b
end
