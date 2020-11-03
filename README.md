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

TODO: Write usage instructions here

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/yoshoku/lbfgsb.

## License

The gem is available as open source under the terms of the [BSD-3-Clause License](https://opensource.org/licenses/BSD-3-Clause).
In addition, L-BFGS-B carries the following condition for use:

This software is freely available, but we expect that all publications describing  work using this software ,
or all commercial products using it, quote at least one of the references given below.
This software is released under the "New BSD License" (aka "Modified BSD License" or "3-clause license").
