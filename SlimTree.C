#include <iostream>

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"

using namespace std;

void SlimTree(TString old_tree_path, TString new_tree_path, TString filename){
  
  //gSystem->Load("$ROOTSYS/test/libEvent");

  //Get old file, old tree and set top branch address
  TFile *oldfile = new TFile(old_tree_path+filename);
  
  TH2F* h1 = (TH2F*)oldfile->Get("signatureCorrelationHisto");
  TH1F* h2 = (TH1F*)oldfile->Get("noCutSignature_TrueNumInteractions");
  TH1F* h3 = (TH1F*)oldfile->Get("noCutSignature_COUNT");

  TTree *oldtree = (TTree*)oldfile->Get("treeR");
  //Event *event   = new Event();

  oldtree->SetBranchStatus("*",0);
  oldtree->SetBranchStatus("NSinglePhoton50Triggers",               1);
  oldtree->SetBranchStatus("NBASICCALOJETS1PT20",                   1);
  oldtree->SetBranchStatus("NBASICCALOJETS1PT20NOPHOTONS",          1);
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETS",             1);
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETSG",             1);
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETSE",             1);
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETSENOPHOTONS",    1);
  oldtree->SetBranchStatus("NMEDIUMPHOTONS",                        1);
  oldtree->SetBranchStatus("HT",                                    1);
  oldtree->SetBranchStatus("PTOSSF",                                1);
  oldtree->SetBranchStatus("ETAOSSF",                               1);
  oldtree->SetBranchStatus("MOSSF",                                 1);
  oldtree->SetBranchStatus("PT_MEDIUMPHOTONS",                      1);
  oldtree->SetBranchStatus("PT_BASICCALOJETS1PT20",                 1);
  oldtree->SetBranchStatus("PT_BASICCALOJETS1PT20NOPHOTONS",        1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETS",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSG",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSE",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSENOPHOTONS",  1);
  oldtree->SetBranchStatus("ETA_MEDIUMPHOTONS",                     1);
  oldtree->SetBranchStatus("ETA_BASICCALOJETS1PT20",                1);
  oldtree->SetBranchStatus("ETA_BASICCALOJETS1PT20NOPHOTONS",       1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETS",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSG",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSE",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSENOPHOTONS", 1);
  oldtree->SetBranchStatus("NHEAVY23",                              1);
  oldtree->SetBranchStatus("NHEAVY51",                              1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETSE",     1);
  oldtree->SetBranchStatus("ALPHAMAX_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETSE",     1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETSE",     1);
  oldtree->SetBranchStatus("NGOODVERTICES",     1);
  oldtree->SetBranchStatus("NGOODMUONS",     1);
  oldtree->SetBranchStatus("NGOODELECTRONS",     1);
  oldtree->SetBranchStatus("hasGoodVertex",     1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETSE",     1);
  oldtree->SetBranchStatus("SELFDELTAR_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETSE",     1);

  //pv, electron, npv, njets, delta r, alpha, ipsig, nracks  -BOTH JET AND TAG
 
 //Create a new file + a clone of old tree in new file
  TFile *newfile = new TFile(new_tree_path+"slim_"+filename,"recreate");
  TTree *newtree = oldtree->CloneTree();

  h1->Write();
  h2->Write();
  h3->Write();

  newtree->Print();
  newfile->Write();
  delete oldfile;
  delete newfile;
}

