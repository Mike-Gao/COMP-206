#!/bin/bash

# The following should fail
./reverse
./reverse bob
./reverse bob bob bob

# The following should return FALSE
./reverse bob Bob
./reverse bob mary
./reverse mary bob

# The following should return TRUE
./reverse bob bob
./reverse mary yram

