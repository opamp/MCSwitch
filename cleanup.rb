#!/usr/bin/env ruby
#-*- encoding:utf-8 -*-

unless RbConfig::CONFIG["host_os"] =~ /^darwin.+/ then
	puts "This app is for MacOSX."
	exit 1
end

puts  "rm -fr $HOME/.MCSwitch"
system("rm -fr ~/.MCSwitch")

puts "delete " + ENV['HOME']+"/Library/Application Support/minecraft/.mcswitch.xml"
File::delete(ENV['HOME']+"/Library/Application Support/minecraft/.mcswitch.xml")
