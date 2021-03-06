typedef struct _drawopt 
{
  const char* volume;
  int         color;
} drawopt;

larsmall_geo(TString volName="")
{
  gSystem->Load("libGeom");
  gSystem->Load("libGdml");

  TGeoManager::Import("larsmall.gdml");

  drawopt optuboone[] = {
    {"volWorld",        0},
    {"volDetEnclosure", kWhite},
    {"volCryostat",     kOrange},
    {"volTPC",          kOrange-5},
    {"volTPCBackWall",  kRed},
    {"volTPCVertWall",  kCyan-5},
    {"volTPCHorizWall", kOrange},
    {"volTPCActive",	kGreen},
    {0, 0}
  };

  // for (int i=0;; ++i) {
  //   if (optuboone[i].volume==0) break;
  //     gGeoManager->FindVolumeFast(optuboone[i].volume)->SetLineColor(optuboone[i].color);
  // }
  TList* mat = gGeoManager->GetListOfMaterials();
  TIter next(mat);
  TObject *obj;
  while (obj = next()) {
    obj->Print();
  }

  gGeoManager->GetTopNode();
  gGeoManager->CheckOverlaps(0.01);
  gGeoManager->PrintOverlaps();
  gGeoManager->SetMaxVisNodes(70000);

  //gGeoManager->GetTopVolume()->Draw();
  if ( ! volName.IsNull() ) gGeoManager->FindVolumeFast(volName)->Draw("ogl");
  //if ( ! volName.IsNull() ) gGeoManager->FindVolumeFast("volTPC")->Draw("ogl");

  TFile *tf = new TFile("larsmall.root", "RECREATE");
 
  gGeoManager->Write();

  tf->Close();
}
