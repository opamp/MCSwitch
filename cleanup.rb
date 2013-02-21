#!/usr/bin/env ruby
#-*- encoding:utf-8 -*-

=begin
This script deletes all data which are made by MCSwitch.
=end

unless RbConfig::CONFIG["host_os"] =~ /^darwin.+/ then
	puts "This script is for MacOSX."
	exit 1
end

puts "rm -f $HOME/Library/Application Support/minecraft"
system("rm -f $HOME/Library/Application Support/minecraft")
puts "mv $HOME/.MCSwitch/env/InitialEnv $HOME/Application Support/minecraft"
system("mv $HOME/.MCSwitch/env/InitialEnv $HOME/Application Support/minecraft")
puts  "rm -fr $HOME/.MCSwitch"
system("rm -fr ~/.MCSwitch")

if File.exist?(ENV['HOME']+"/Library/Application Support/minecraft/.mcswitch.xml") == true then
	puts "delete " + ENV['HOME']+"/Library/Application Support/minecraft/.mcswitch.xml"
	File::delete(ENV['HOME']+"/Library/Application Support/minecraft/.mcswitch.xml")
end
