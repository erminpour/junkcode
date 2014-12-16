#!/usr/bin/python -tt

import yum


def main():
    yb = yum.YumBase()
    yb.doTsSetup()
    pkgList = ["k3b", "kernel-devel", "mysql", "mysql-server"]
    toDownload = []

   # pos = yb.pkgSack.returnPackages(patterns=pkgList)
    pos = yb.pkgSack.returnNewestByNameArch(patterns=pkgList)
    toDownload.extend(pos)

    print "RPM Packages:"
    for po in toDownload:
        print po
    print

    yb.doTsSetup()
    # Act as if we were to install the packages in toDownload
    for po in toDownload:
        yb.tsInfo.addInstall(po)
        yb.localPackages.append(po)
    # Resolve dependencies
    yb.resolveDeps()

    # Add newly added packages to the toDownload list
    for pkg in yb.tsInfo.getMembers():
        if not pkg in toDownload:
            toDownload.append(pkg)

    print "RPM Packages plus DEPS:"
    for po in toDownload:
        print po

if __name__ == "__main__":
    main()
