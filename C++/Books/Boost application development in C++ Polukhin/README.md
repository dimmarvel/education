# Run boost

Build:
Install some version from here https://www.boost.org/

```
    tar -xzf *.tar.gz
    ./bootstrap.sh --prefix=/usr/lib
    ./b2
    sudo ./b2 --prefix=/usr/bin install
```

---
Some refs:
1. https://www.baeldung.com/linux/boost-install-on-ubuntu help first steps
2. Other steps help https://web.archive.org/web/20220203120431/https://stackoverflow.com/questions/12578499/how-to-install-boost-on-ubuntu