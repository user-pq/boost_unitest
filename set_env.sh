unset LD_LIBRARY_PATH

PATH=$PATH:$HOME/.local/bin:$HOME/bin

export PATH
export BOOST_ROOT=$(pwd)/boost_1_62_0
export BOOST_BUILD_LIB=/usr/local/lib/

ulimit -c unlimited

export LD_LIBRARY_PATH


