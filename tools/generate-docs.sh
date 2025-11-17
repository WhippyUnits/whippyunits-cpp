#!/bin/bash

set -e

mkdir -p build/html/docs
doxygen docs/Doxyfile
