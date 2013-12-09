# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'spf2/version'

Gem::Specification.new do |spec|
  spec.name          = "spf2"
  spec.version       = Spf2::VERSION
  spec.authors       = ["Romeu Fonseca"]
  spec.email         = ["romeu.hcf@gmail.com"]
  spec.description   = %q{Native libspf2 basic wrapper}
  spec.summary       = %q{Simple query interface to native libspf2. Will be more complete later.}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.extensions = %w[ext/spf2/extconf.rb]
  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
end
