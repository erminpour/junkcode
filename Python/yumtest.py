#!/usr/bin/python

import yum

class YumTest(yum.YumBase):
    def __init__(self):
        yum.YumBase.__init__(self)
        self.conf.errorlevel = 0
        print self.conf.errorlevel

        for count, rpm in enumerate(self.rpmdb):
            print "%d %s" % (count, rpm)
        print "%d RPMs installed." % count

        #pkgs = self.rpmdb.returnPackages()
        pkgs = self.pkgSack.returnPackages()
        for pkg in pkgs:
            print "NAME-VERSION-RELEASE.ARCH = %s-%s-%s.%s" \
                    % (pkg.name, pkg.version, pkg.release, pkg.arch)
        print self.localPackages

        ## name, arch, epoch, version, release, 
        ## summary, description, pkgid, packageSize

        #print self.repos.listEnabled()

        #all_pkgs = self.rpmdb.returnPackages()
        #all_versions = self.pkgSack.returnPackages()

        #print all_versions

YumTest()


