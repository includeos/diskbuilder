#!/bin/bash

set -e
set -x
if [[ "$(uname -s)" == 'Darwin' ]]; then
    HOMEBREW_NO_AUTO_UPDATE=1 brew install cmake || :
    HOMEBREW_NO_AUTO_UPDATE=1 brew install python3 || :
fi
pip3 install conan --upgrade
