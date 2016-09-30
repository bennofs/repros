let
  configuration = { config, pkgs, ... }: {
    imports = [ ./configuration.nix ./hardware-configuration.nix ./vm-accounts.nix ];
    virtualisation.diskSize = 2048;
    virtualisation.memorySize = 1024;
  };
  build = import <nixpkgs/nixos> { inherit configuration; };
in build.vm
