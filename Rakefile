require 'bundler/gem_tasks'
require 'rspec/core/rake_task'

RSpec::Core::RakeTask.new(:spec)

require 'rake/extensiontask'

task :build => :compile

Rake::ExtensionTask.new('lbfgsbext') do |ext|
  ext.ext_dir = 'ext/lbfgsb'
  ext.lib_dir = 'lib/lbfgsb'
end

task :default => [:clobber, :compile, :spec]
