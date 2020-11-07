# Lbfgsb.rb
Lbfgsb.rb is a Ruby binding for [L-BFGS-B](http://users.iems.northwestern.edu/~nocedal/lbfgsb.html)
that is a limited-memory algorithm for solving large nonlinear optimization problems
subject to simple bounds on the variables.
L-BFGS-B is written in FORTRAN. Author converted the codes into C-lang
and call that with Ruby native exntesion.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'lbfgsb'
```

And then execute:

    $ bundle install

Or install it yourself as:

    $ gem install lbfgsb

## Usage
Example 1. Logistic Regression

```ruby
require 'numo/narray'
require 'lbfgsb'
require 'rumale'


## Training:
# Define objective function and its derivative.
obj_fnc = proc do |w, x, y|
  Numo::NMath.log(1 + Numo::NMath.exp(-y * x.dot(w))).sum
end

d_obj_fnc = proc do |w, x, y|
  (y / (1 + Numo::NMath.exp(-y * x.dot(w))) - y).dot(x)
end

# Load dataset.
x, y = Rumale::Dataset.load_libsvm_file('svmguide3')

# Extend variable for intercept.
xb = Numo::DFloat.hstack([x, Numo::DFloat.ones(x.shape[0]).expand_dims(1)])

# Initialize weight vector.
w0 = xb.mean(0)

# Optimize weight vector.
res = Lbfgsb.minimize(fnc: obj_fnc, jcb: d_obj_fnc, x_init: w0, args: [xb, y])
pp res
w = res[:x]


## Testing:
# Load dataset.
x_test, y_test = Rumale::Dataset.load_libsvm_file('svmguide3.t')
xb_test = Numo::DFloat.hstack([x_test, Numo::DFloat.ones(x_test.shape[0]).expand_dims(1)])

# Predict class label.
probs = 1.0 / (Numo::NMath.exp(-xb_test.dot(w)) + 1.0)
predicted = Numo::Int32.zeros(x_test.shape[0])
predicted[probs >= 0.5] = 1
predicted[probs <  0.5] =-1

# Evaluate result.
evaluator = Rumale::EvaluationMeasure::Accuracy.new
puts("Accuracy: %.1f%%" % (100.0 * evaluator.score(predicted, y_test)))
```

```sh
$ gem install rumale
$ wget https://www.csie.ntu.edu.tw/~cjlin/libsvmtools/datasets/binary/svmguide3
$ wget https://www.csie.ntu.edu.tw/~cjlin/libsvmtools/datasets/binary/svmguide3.t
$ ruby example1.rb
{:task=>"CONVERGENCE: REL_REDUCTION_OF_F_<=_FACTR*EPSMCH",
 :x=>
  Numo::DFloat#shape=[23]
[6.36634, -86.6413, -18.9489, -11.4564, -16.6738, -23.9111, -6.19714, ...],
 :fnc=>512.3210359536802,
 :jcb=>
  Numo::DFloat#shape=[23]
[8.01782e-05, -0.000226254, -0.00144915, 4.26451e-05, 0.000677138, ...],
 :n_iter=>623,
 :n_fev=>716,
 :n_jev=>716,
 :success=>true}
Accuracy: 61.0%
```

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/yoshoku/lbfgsb.

## License

The gem is available as open source under the terms of the [BSD-3-Clause License](https://opensource.org/licenses/BSD-3-Clause).
In addition, L-BFGS-B carries the following condition for use:

This software is freely available, but we expect that all publications describing  work using this software ,
or all commercial products using it, quote at least one of the references given below.
This software is released under the "New BSD License" (aka "Modified BSD License" or "3-clause license").
