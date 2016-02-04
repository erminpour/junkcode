#!/bin/bash

/usr/bin/openssl genrsa 2048 > intellego_private.key
/usr/bin/openssl req \
                -new \
                -x509 \
                -key intellego_private.key \
                -out intellego_certificate.pem \
                -days 365

