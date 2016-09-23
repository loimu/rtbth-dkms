This is a kernel module for Ralink RT3290 chip which makes it work with Bluez
software and driver.

This module has no official support by Mediatek. Support was discontinued.


### Usage: ###

```sh
# Init
sudo modprobe rtbth
sudo rfkill unblock bluetooth
hcitool dev # check

# Switch off
sudo rfkill block bluetooth

# Switch on
sudo rfkill unblock bluetooth

# Shutdown
sudo pkill -2 rtbt
sudo rmmod rtbth
```


### Blob issues: ###

No support for Bluetooth Protocol v4.0 and more recent.
Configure your devices to use legacy mode.
