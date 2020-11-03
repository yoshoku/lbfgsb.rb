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
