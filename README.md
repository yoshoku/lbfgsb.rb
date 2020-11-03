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

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/[USERNAME]/lbfgsb.

