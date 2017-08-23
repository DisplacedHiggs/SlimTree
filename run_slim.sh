#!/bin/bash

MAINDIR=`pwd`
ls

export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
export COIN_FULL_INDIRECT_RENDERING=1
echo $VO_CMS_SW_DIR
source $VO_CMS_SW_DIR/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc493
tar xzf CMSSW_8_0_18_patch1.tar.gz
cd CMSSW_8_0_18_patch1/src
scram b ProjectRename
eval `scramv1 runtime -sh`
cd -

echo "arg0 $0"
echo "arg1 $1"
echo "arg2 $2"
echo "arg3 $3"
echo "arg4 $4"
echo "arg5 $5"
echo "arg6 $6"

echo "xrdcp $1/$3 $3"
xrdcp $1/$3 $3
#root -l -b -q "SlimTree.C+(\"$1\",\"$2\",\"$3\")"
root -l -b -q "SlimTree.C+(\"\",\"\",\"$3\")"
ls
echo "xrdcp slim_$3 $2/slim_$3"
xrdcp slim_$3 $2/slim_$3

echo "Inside $MAINDIR:"
ls
echo "DELETING..."
rm *.root
rm -r CMSSW_8_0_18_patch1
rm CMSSW_8_0_18_patch1.tar.gz
rm SlimTree.C
ls