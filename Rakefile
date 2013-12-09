require "bundler/gem_tasks"


require 'rake/extensiontask'

##
# Rake::ExtensionTask comes from the rake-compiler and understands how to
# build and cross-compile extensions.
#
# See https://github.com/luislavena/rake-compiler for details

Rake::ExtensionTask.new 'spf2' do |ext|
  ext.lib_dir = 'lib/spf2'
end

task test: %w[compile] do
  ruby '-Ilib', '-rspf2', '-e', 's = Spf2.new(false); s.debug=(true); s.debug=(false); p s.query("186.224.205.179", "cmacomunicacao.com.br")'
end

task default: :test
