# frozen_string_literal: true

RSpec.describe Lbfgsb do
  describe 'driver1' do
    shared_examples 'optimization' do
      subject { described_class.minimize(fnc: fnc, x_init: x, jcb: jcb, args: n, bounds: b, maxcor: m, verbose: -1) }

      let(:n) { 25 }
      let(:m) { 5 }
      let(:x) { Numo::DFloat.zeros(n) + 3 }
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

      it do
        expect(subject).to include(
          task: start_with('CONV'),
          fnc: be_within(1e-10).of(1.0834900834300615e-09),
          n_iter: eq(23),
          success: be_truthy,
          x: be_a(Numo::DFloat),
          jcb: be_a(Numo::DFloat)
        )
      end
    end

    context 'when calculating the funcation value and gradient vector with separate procs' do
      let(:fnc) do
        proc do |x, n|
          f = 0.25 * (x[0] - 1)**2
          (1...n).each do |i|
            f += (x[i] - x[i - 1]**2)**2
          end
          f * 4.0
        end
      end

      let(:jcb) do
        proc do |x, n|
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

      it_behaves_like 'optimization'
    end

    context 'when calculating the funcation value and gradient vector in the same proc' do
      let(:fnc) do
        proc do |x, n|
          # calculate function value
          f = 0.25 * (x[0] - 1)**2
          (1...n).each do |i|
            f += (x[i] - x[i - 1]**2)**2
          end
          f *= 4.0
          # calculate gradient vector
          g = Numo::DFloat.zeros(n)
          t1 = x[1] - x[0]**2
          g[0] = 2.0 * (x[0] - 1.0) - 16.0 * x[0] * t1
          (1...(n - 1)).each do |i|
            t2 = t1
            t1 = x[i + 1] - x[i]**2
            g[i] = 8.0 * t2 - 16.0 * x[i] * t1
          end
          g[n - 1] = t1 * 8.0
          # return set of value and vector
          [f, g]
        end
      end

      let(:jcb) { true }

      it_behaves_like 'optimization'
    end
  end
end
