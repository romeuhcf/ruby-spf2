# Spf2

Simple native wrapper over the C lib SPF2. 
At the moment it just have a query method that returns three strings with result, reason and error:

["pass", "mechanism", "No errors"]


## Installation

Add this line to your application's Gemfile:

    gem 'spf2'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install spf2

## Usage
```
require 'spf2'

s =  Spf2.new(debug=false)
s.debug = true
s.query("173.194.65.27", "gmail.com")

```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request



