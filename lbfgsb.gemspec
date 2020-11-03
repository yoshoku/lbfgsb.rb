require_relative 'lib/lbfgsb/version'

Gem::Specification.new do |spec|
  spec.name          = 'lbfgsb'
  spec.version       = Lbfgsb::VERSION
  spec.authors       = ['yoshoku']
  spec.email         = ['yoshoku@outlook.com']

  spec.summary       = 'Lbfgsb.rb is a Ruby binding for L-BFGS-B'
  spec.description   = 'Lbfgsb.rb is a Ruby binding for L-BFGS-B'
  spec.homepage      = 'https://github.com/yoshoku/lbfgsb.rb'
  spec.license       = 'BSD-3-Clause'

  spec.metadata['homepage_uri'] = spec.homepage
  spec.metadata['source_code_uri'] = 'https://github.com/yoshoku/lbfgsb.rb'
  spec.metadata['changelog_uri'] = 'https://github.com/yoshoku/lbfgsb.rb/CHANGELOG.md'

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end
  spec.bindir        = 'exe'
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ['lib']
  spec.extensions    = ['ext/lbfgsb/extconf.rb']

  spec.add_runtime_dependency 'numo-narray', '>= 0.9.1'
end
