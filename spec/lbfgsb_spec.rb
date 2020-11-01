RSpec.describe Lbfgsb do
  it "has a version number" do
    expect(Lbfgsb::VERSION).not_to be nil
  end

  it 'driver1' do
    n = 25
    m = 5
    x = Numo::DFloat.zeros(n) + 3
    l = Numo::DFloat.zeros(n)
    u = Numo::DFloat.zeros(n)
    nbd = Numo::Int64.zeros(n)

    0.step(n - 1, 2) do |i|
      nbd[i] = 2
      l[i] = 1
      u[i] = 100
    end

    1.step(n - 1, 2) do |i|
      nbd[i] = 2
      l[i] = -100
      u[i] = 100
    end

    args = { n: n }

    fnc = proc do |x, args|
      n = args[:n]
      f = 0.25 * (x[0] - 1)**2
      (1...n).each do |i|
        f += (x[i] - x[i - 1]**2)**2
      end
      f * 4.0
    end

    jcb = proc do |x, args|
      n = args[:n]
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

    res = Lbfgsb.minimize(fnc, x, jcb, args, l, u, nbd, m, 1e7, 1e-5, 100, 1)
  end
end
