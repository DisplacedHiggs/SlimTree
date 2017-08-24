#include <iostream>

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"

using namespace std;

void SlimTree(TString old_tree_path, TString new_tree_path, TString filename){
  //gSystem->Load("$ROOTSYS/test/libEvent");

  bool doPATJetMatching = true; 
  bool verbose = true;

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
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETS",              1);
  oldtree->SetBranchStatus("NINCLUSIVETAGGEDCALOJETSC",             1);
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
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETS",            1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSC",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSG",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSE",           1);
  oldtree->SetBranchStatus("PT_INCLUSIVETAGGEDCALOJETSENOPHOTONS",  1);
  oldtree->SetBranchStatus("ETA_MEDIUMPHOTONS",                     1);
  oldtree->SetBranchStatus("ETA_BASICCALOJETS1PT20",                1);
  oldtree->SetBranchStatus("ETA_BASICCALOJETS1PT20NOPHOTONS",       1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETS",           1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSC",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSG",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSE",          1);
  oldtree->SetBranchStatus("ETA_INCLUSIVETAGGEDCALOJETSENOPHOTONS", 1);
  oldtree->SetBranchStatus("PHI_BASICCALOJETS1PT20",                1);
  oldtree->SetBranchStatus("PHI_INCLUSIVETAGGEDCALOJETSE",          1);
  oldtree->SetBranchStatus("NHEAVY23",                              1);
  oldtree->SetBranchStatus("NHEAVY51",                              1);
  oldtree->SetBranchStatus("NHEAVY",                                1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_BASICCALOJETS1PT20",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETS",      1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETSC",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETSG",     1);
  oldtree->SetBranchStatus("NMATCHEDTRACKS_INCLUSIVETAGGEDCALOJETSE",     1);
  oldtree->SetBranchStatus("ALPHAMAX_BASICCALOJETS1PT20",                 1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETS",            1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETSC",           1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETSG",           1);
  oldtree->SetBranchStatus("ALPHAMAX_INCLUSIVETAGGEDCALOJETSE",           1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_BASICCALOJETS1PT20",         1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETS",    1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETSC",   1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETSG",   1);
  oldtree->SetBranchStatus("MEDIANIPLOG10SIG_INCLUSIVETAGGEDCALOJETSE",   1);
  oldtree->SetBranchStatus("NGOODVERTICES",     1);
  oldtree->SetBranchStatus("NGOODMUONS",        1);
  oldtree->SetBranchStatus("NGOODELECTRONS",    1);
  //oldtree->SetBranchStatus("hasGoodVertex",     1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_BASICCALOJETS1PT20",         1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETS",    1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETSC",   1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETSG",   1);
  oldtree->SetBranchStatus("BASICCALOJETS1PT20DELTAR_INCLUSIVETAGGEDCALOJETSE",   1);
  oldtree->SetBranchStatus("SELFDELTAR_BASICCALOJETS1PT20",          1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETS",     1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETSC",    1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETSG",    1);
  oldtree->SetBranchStatus("SELFDELTAR_INCLUSIVETAGGEDCALOJETSE",    1);
  if(doPATJetMatching){
    oldtree->SetBranchStatus("PT_BASICPATJETSPT15",      1);
    oldtree->SetBranchStatus("ETA_BASICPATJETSPT15",     1);
    oldtree->SetBranchStatus("PHI_BASICPATJETSPT15",     1);
    oldtree->SetBranchStatus("PARTONFLAVOUR_BASICPATJETSPT15",     1);
    oldtree->SetBranchStatus("PFCOMBINEDINCLUSIVESECONDARYVERTEXV2BJETTAGS_BASICPATJETSPT15",     1);
    //oldtree->SetBranchStatus("PT_ALLPATJETS",      1);
    //oldtree->SetBranchStatus("ETA_ALLPATJETS",     1);
    //oldtree->SetBranchStatus("PHI_ALLPATJETS",     1);
    //oldtree->SetBranchStatus("PARTONFLAVOUR_ALLPATJETS",     1);
    //oldtree->SetBranchStatus("PFCOMBINEDINCLUSIVESECONDARYVERTEXV2BJETTAGS_ALLPATJETS",     1);
  }
  
  
  //Create a new file + a clone of old tree in new file
  TFile *newfile = new TFile(new_tree_path+"slim_"+filename,"recreate");
  TTree *newtree = oldtree->CloneTree();

  //////////////////////////////////////
  //Do CSV and partonFlavour matching
  //////////////////////////////////////

  //Existing
  std::vector<float> *b_ETA_BASICCALOJETS1PT20                 = new std::vector<float>();
  std::vector<float> *b_PHI_BASICCALOJETS1PT20                 = new std::vector<float>();
  std::vector<float> *b_ETA_INCLUSIVETAGGEDCALOJETSE           = new std::vector<float>();
  std::vector<float> *b_PHI_INCLUSIVETAGGEDCALOJETSE           = new std::vector<float>();
  std::vector<float> *b_ETA_BASICPATJETSPT15                   = new std::vector<float>();
  std::vector<float> *b_PHI_BASICPATJETSPT15                   = new std::vector<float>();
  std::vector<int>   *b_PARTONFLAVOUR_BASICPATJETSPT15         = new std::vector<int>();
  std::vector<float> *b_CSV_BASICPATJETSPT15  = new std::vector<float>();
  newtree->SetBranchAddress("ETA_BASICCALOJETS1PT20",           &b_ETA_BASICCALOJETS1PT20); 
  newtree->SetBranchAddress("PHI_BASICCALOJETS1PT20",           &b_PHI_BASICCALOJETS1PT20); 
  newtree->SetBranchAddress("ETA_INCLUSIVETAGGEDCALOJETSE",     &b_ETA_INCLUSIVETAGGEDCALOJETSE); 
  newtree->SetBranchAddress("PHI_INCLUSIVETAGGEDCALOJETSE",     &b_PHI_INCLUSIVETAGGEDCALOJETSE); 
  newtree->SetBranchAddress("ETA_BASICPATJETSPT15",             &b_ETA_BASICPATJETSPT15); 
  newtree->SetBranchAddress("PHI_BASICPATJETSPT15",             &b_PHI_BASICPATJETSPT15); 
  newtree->SetBranchAddress("PARTONFLAVOUR_BASICPATJETSPT15",   &b_PARTONFLAVOUR_BASICPATJETSPT15); 
  newtree->SetBranchAddress("PFCOMBINEDINCLUSIVESECONDARYVERTEXV2BJETTAGS_BASICPATJETSPT15", &b_CSV_BASICPATJETSPT15); 


  //New
  std::vector<float> matchedcsv_basiccalojets1pt20;
  std::vector<float> matchedcsv_inclusivetaggedcalojetse;
  std::vector<int> matchedpartonflavour_basiccalojets1pt20;
  std::vector<int> matchedpartonflavour_inclusivetaggedcalojetse;
  TBranch* b_matchedcsv_basiccalojets1pt20 = newtree->Branch("MATCHEDCSV_BASICCALOJETS1PT20", "vector<float>", &matchedcsv_basiccalojets1pt20);
  TBranch* b_matchedcsv_inclusivetaggedcalojetse = newtree->Branch("MATCHEDCSV_INCLUSIVETAGGEDCALOJETSE", "vector<float>", &matchedcsv_inclusivetaggedcalojetse);
  TBranch* b_matchedpartonflavour_basiccalojets1pt20 = newtree->Branch("MATCHEDPARTONFLAVOUR_BASICCALOJETS1PT20", "vector<int>", &matchedpartonflavour_basiccalojets1pt20);
  TBranch* b_matchedpartonflavour_inclusivetaggedcalojetse = newtree->Branch("MATCHEDPARTONFLAVOUR_INCLUSIVETAGGEDCALOJETSE", "vector<int>", &matchedpartonflavour_inclusivetaggedcalojetse);

  Long64_t nentries = newtree->GetEntries();
  for (Long64_t i = 0; i < nentries; i++) {
    if(verbose) cout << "Event: " << i << endl;
    newtree->GetEntry(i);
    
    //Clear new vectors
    matchedcsv_basiccalojets1pt20.clear();
    matchedcsv_inclusivetaggedcalojetse.clear();
    matchedpartonflavour_basiccalojets1pt20.clear();
    matchedpartonflavour_inclusivetaggedcalojetse.clear();
    
    //Loop over untagged jets
    for(unsigned int j=0; j<b_ETA_BASICCALOJETS1PT20->size(); j++){
      if(verbose) cout << "   Jet: " << j << endl;
      float calo_eta = b_ETA_BASICCALOJETS1PT20->at(j);
      float calo_phi = b_PHI_BASICCALOJETS1PT20->at(j);
      
      int best_match_index = -1;
      float min_dr = 0.5;//match must be within 0.5
      //Loop over PAT jets to find best match (currently pat jet can be used more than once)
      for(unsigned int k=0; k<b_ETA_BASICPATJETSPT15->size(); k++){
	float pat_eta = b_ETA_BASICPATJETSPT15->at(k);
	float pat_phi = b_PHI_BASICPATJETSPT15->at(k);
	float my_dr = TMath::Sqrt( (calo_eta-pat_eta)*(calo_eta-pat_eta) + (calo_phi-pat_phi)*(calo_phi-pat_phi) );
	if(verbose) cout << "      DR with " << k << ": " << my_dr << " -- " << b_CSV_BASICPATJETSPT15->at(k) << " " << b_PARTONFLAVOUR_BASICPATJETSPT15->at(k) << endl;
	if(my_dr < min_dr) best_match_index = k;
      }
      
      //Insert match
      if(best_match_index>=0){
	matchedcsv_basiccalojets1pt20.push_back( b_CSV_BASICPATJETSPT15->at(best_match_index) );
	matchedpartonflavour_basiccalojets1pt20.push_back( b_PARTONFLAVOUR_BASICPATJETSPT15->at(best_match_index) );
      }
      else{//no match
	matchedcsv_basiccalojets1pt20.push_back( 0 );
	matchedpartonflavour_basiccalojets1pt20.push_back( -999 );
      }
      
      if(verbose){
	cout << "         Chose CSV: " << matchedcsv_basiccalojets1pt20.at(j) << " from " << best_match_index << endl;
        cout << "         Chose PF:  " << matchedpartonflavour_basiccalojets1pt20.at(j) << " from " << best_match_index << endl;
      }

    }//end loop over untagged jets


    //Loop over tagged jets
    for(unsigned int j=0; j<b_ETA_INCLUSIVETAGGEDCALOJETSE->size(); j++){
      float calo_eta = b_ETA_INCLUSIVETAGGEDCALOJETSE->at(j);
      float calo_phi = b_PHI_INCLUSIVETAGGEDCALOJETSE->at(j);
      
      int best_match_index = -1;
      float min_dr = 99999;
      //Loop over PAT jets to find best match (currently pat jet can be used more than once)
      for(unsigned int k=0; k<b_ETA_BASICPATJETSPT15->size(); k++){
	float pat_eta = b_ETA_BASICPATJETSPT15->at(k);
	float pat_phi = b_PHI_BASICPATJETSPT15->at(k);
	float my_dr = TMath::Sqrt( (calo_eta-pat_eta)*(calo_eta-pat_eta) + (calo_phi-pat_phi)*(calo_phi-pat_phi) );
	if(my_dr < min_dr) best_match_index = k;
      }
      
      //Insert match
      if(best_match_index>=0){
	matchedcsv_inclusivetaggedcalojetse.push_back( b_CSV_BASICPATJETSPT15->at(best_match_index) );
	matchedpartonflavour_inclusivetaggedcalojetse.push_back( b_PARTONFLAVOUR_BASICPATJETSPT15->at(best_match_index) );
      }
      else{//no match
	matchedcsv_inclusivetaggedcalojetse.push_back( 0 );
	matchedpartonflavour_inclusivetaggedcalojetse.push_back( -999 );
      }
      
    }//end loop over untagged jets

    //Fill new branches
    b_matchedcsv_basiccalojets1pt20->Fill();
    b_matchedcsv_inclusivetaggedcalojetse->Fill();
    b_matchedpartonflavour_basiccalojets1pt20->Fill();
    b_matchedpartonflavour_inclusivetaggedcalojetse->Fill();
  }
  //////////////////////////////////////// end of matching


  //Add histograms
  h1->Write();
  h2->Write();
  h3->Write();

  newtree->Print();
  newfile->Write();
  delete oldfile;
  delete newfile;
}

