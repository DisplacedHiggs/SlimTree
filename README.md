# SlimTree

# Instructions

First, create tarball of CMSSW release, CMSSW_8_0_18_patch1.tar.gz.

Check INPATH in create.sh and the samples you want in processes.list

Then
```
./create.sh
condor_submit submit_all.condor
```