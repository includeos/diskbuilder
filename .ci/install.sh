#!/bin/bash

set -e
set -x
#ls -A | grep -v src | xargs rm -r || :
if [[ "$(uname -s)" == 'Darwin' ]]; then
    brew update || brew update
    brew install cmake || true
fi
pip install conan --upgrade
pip install conan_package_tools bincrafters_package_tools
conan user
