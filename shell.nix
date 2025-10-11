{
    pkgs ? import <nixpkgs> {},
    diskbuilder ? import ./default.nix { inherit pkgs; },
}
:
pkgs.mkShell {
    packages = [
        diskbuilder
    ];
}
