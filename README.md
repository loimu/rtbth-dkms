# RTBTH-DKMS Fork

This repository is a fork of the original **rtbth-dkms** driver.

## Purpose

The **rtbth-dkms** driver does not support Linux kernels beyond version 6.10. This repository was created to address this limitation by adapting the driver to work with newer kernels.

### Issue Details
The problem arises due to changes introduced in newer kernels that break compatibility with the original driver. Specifically, this [commit](https://lore.kernel.org/linux-cve-announce/2024062047-CVE-2024-38620-64ef@gregkh/T/) in the Linux kernel caused the issue.

### Community Discussion
For more context and discussions regarding this problem, see the [Arch Linux Forum thread](https://bbs.archlinux.org/viewtopic.php?id=298200).

## Contributions
Contributions to improve and maintain this fork are welcome. Please feel free to submit pull requests or open issues.

## License
This project inherits the license of the original **rtbth-dkms** driver.
