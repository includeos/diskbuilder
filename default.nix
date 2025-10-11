{
  pkgs ? import <nixpkgs> {},
}
:
pkgs.stdenv.mkDerivation {
  name = "IncludeOS diskbuilder";
  src = ./.;
  
  buildInputs = with pkgs; [ 
    clang
    gnumake
    cmake
  ];
  
  buildPhase = ''
    cmake ..
    make VERBOSE=1
  '';
  
  installPhase = ''
    mkdir -p $out/bin
    cp diskbuilder $out/bin/
  '';
}
