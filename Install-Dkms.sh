#!/usr/bin/bash -eux

#export DH_VERBOSE=1

name=rtbth
pkgdir=$name-dkms
version=3.9.8
prefix="${prefix:-/usr/local}"

override_dh_auto_install() {
	# patch the rtbt binary with a newer firmware
	cp tools/rt3298_new.bin rt3298_new.bin
	cp tools/rtbt rtbt
	cp tools/upgrade-firmware.sh upgrade-firmware.sh
	sh upgrade-firmware.sh
	mv -f rtbt tools/rtbt
	rm rt3298_new.bin
	rm upgrade-firmware.sh
	# do the other stuff
	sudo mkdir -pv $prefix/lib/pm-utils/sleep.d
	sudo mkdir -pv /etc/modprobe.d
	sudo mkdir -pv -- $prefix/src/$name-$version/include

	sudo make install

	#dh_shlibdeps debian/${pkgdir}/usr/bin/rtbt
	#sudo install debian/Readme.Debian usr/share/doc/${pkgdir}/
	sudo install -vDm755 *.c Makefile $prefix/src/${name}-${version}/
	# sudo install -vDm755 
	sudo install -vDm755 include/* $prefix/src/${name}-${version}/include

	#instalarea Propriu zisa

	sudo ln -sv -- $prefix/src/$name-$version /usr/src/ || true
	sudo install -vDm755 debian/rtbth-dkms.dkms $prefix/src/$name-$version/dkms.conf 
	sudo dkms add  -m $name -v $version || true
	sudo dkms build -m $name -v $version
	sudo dkms install -m $name -v $version
}

override_dh_auto_install 
