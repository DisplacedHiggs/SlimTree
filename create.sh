#!/bin/bash

MAINDIR=`pwd`
INPATH=/store/user/lpchbb/kreis/AnalysisTrees_PhotonTest_Aug10

LOGDIR=$MAINDIR/logs_slim
mkdir $LOGDIR


condorFile=submit_all.condor
if [ -e $condorFile ]
then
    rm -rf $condorFile
fi
touch $condorFile

echo "universe = vanilla" >> $condorFile
#echo "Requirements = OpSys == \"LINUX\" && (Arch != \"DUMMY\" )" >> $condorFile
echo "Executable = run_slim.sh" >> $condorFile
echo "Should_Transfer_Files = YES" >> $condorFile
#echo "request_disk = 10000000" >> $condorFile
echo "request_memory = 2100" >> $condorFile
echo "WhenTOTransferOutput  = ON_EXIT_OR_EVICT" >> $condorFile
echo "Notification=never" >> $condorFile
echo "notify_user = kreis@fnal.gov" >> $condorFile
echo "x509userproxy = \$ENV(X509_USER_PROXY)" >> $condorFile
echo "Transfer_Input_Files = run_slim.sh, SlimTree.C, CMSSW_8_0_18_patch1.tar.gz" >> $condorFile
echo "" >> $condorFile

processlist=processes.list
while IFS='' read -r line || [[ -n "$line" ]]; do

    dir1=`eos root://cmseos.fnal.gov ls -l $INPATH/$line | awk '{print $9}'`

    OUTPATH=$INPATH/slim/$line
    echo $OUTPATH
    eos root://cmseos.fnal.gov mkdir -p $OUTPATH

    tmplist=tmp.tmp
    #echo $dir1
    echo $dir1| tr " " "\n" > $tmplist

    while IFS='' read -r filename || [[ -n "$filename" ]]; do

	echo "output = $LOGDIR/\$(Cluster)_slim_$filename.out" >> $condorFile
	echo "error = $LOGDIR/\$(Cluster)_slim_$filename.err" >> $condorFile
	echo "log = $LOGDIR/\$(Cluster)_slim_$filename.log" >> $condorFile
	echo "arguments = root://cmseos.fnal.gov/$INPATH/$line/ root://cmseos.fnal.gov/$OUTPATH $filename" >> $condorFile
	echo "queue" >> $condorFile	
	echo "" >> $condorFile

    done < "$tmplist"


done < "$processlist"
