require 'mkmf'
dir_config('spf2')
have_library('spf2') or raise
create_makefile 'spf2/spf2'
