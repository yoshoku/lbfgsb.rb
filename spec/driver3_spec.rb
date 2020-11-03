# frozen_string_literal: true

RSpec.describe Lbfgsb do
  describe 'driver3' do
    let(:n) { 1000 }
    let(:m) { 10 }
    let(:x) { Numo::DFloat.zeros(n) + 3 }
    let(:pgtol) { (5.35267e-22 + 1) * 1e-10 }

    let(:b) do
      bounds = Numo::DFloat.zeros(n, 2)
      0.step(n - 1, 2) do |i|
        bounds[i, 0] = 1
        bounds[i, 1] = 100
      end
      1.step(n - 1, 2) do |i|
        bounds[i, 0] = -100
        bounds[i, 1] = 100
      end
      bounds
    end

    let(:fnc) do
      proc do |x|
        n = x.size
        f = 0.25 * (x[0] - 1)**2
        (1...n).each do |i|
          f += (x[i] - x[i - 1]**2)**2
        end
        f * 4.0
      end
    end

    let(:jcb) do
      proc do |x|
        n = x.size
        g = Numo::DFloat.zeros(n)
        t1 = x[1] - x[0]**2
        g[0] = 2.0 * (x[0] - 1.0) - 16.0 * x[0] * t1
        (1...(n - 1)).each do |i|
          t2 = t1
          t1 = x[i + 1] - x[i]**2
          g[i] = 8.0 * t2 - 16.0 * x[i] * t1
        end
        g[n - 1] = t1 * 8.0
        g
      end
    end

    let(:result) do
      described_class.minimize(fnc: fnc, x_init: x, jcb: jcb, args: n, bounds: b, maxcor: m, factr: 0, pgtol: pgtol)
    end

    it do
      expect(result).to include(
        task: start_with('CONVERGENCE: NORM_OF_PROJECTED_GRADIENT_<=_PGTOL'),
        fnc: be_within(1e-22).of(5.35267e-22),
        n_iter: eq(49),
        success: be_truthy,
        x: have_attributes(size: n),
        jcb: have_attributes(size: n)
      )
    end
  end
end
