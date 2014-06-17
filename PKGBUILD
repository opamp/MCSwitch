pkgname=mcswitch
pkgver=0.4.0
pkgrel=1
pkgdesc="MCSwitch provides environment for you to play plural minecraft versions"
arch=('i686' 'x86_64')
url="https://github.com/opamp/MCSwitch"
license=('BSD')
source=("https://github.com/opamp/MCSwitch/archive/0.4.0.tar.gz")
depends=('qt5-base' 'qt5-xmlpatterns' 'qt5-multimedia' 'qt5-imageformats' 'qt5-tools')
makedepends=('cmake')

build() {
    cd ${srcdir}/MCSwitch-$pkgver
    cmake .
    make
}

package(){
    cd ${srcdir}/MCSwitch-$pkgver
    make DESTDIR="$pkgdir" install
}
