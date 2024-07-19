{
  inputs.nixpkgs.url = github:NixOS/nixpkgs/63dacb46bf939521bdc93981b4cbb7ecb58427a0;
  outputs = { self, nixpkgs }: {
    packages.x86_64-linux.default = (nixpkgs.lib.nixosSystem {
      modules = [
        ({ lib, pkgs, config, modulesPath, ... }: {
          users = {
            mutableUsers = false;
            users.root.password = "";
          };

          systemd.services.test-service = {
            enable = true;
            wantedBy = [ "multi-user.target" ];
            before = [ "nscd.service" ];
            serviceConfig = {
              Type = "oneshot";
              DynamicUser = true;
              ExecStart = "${lib.getBin pkgs.coreutils}/bin/id test-service";
            };
          };
          services.getty.autologinUser = "root";

          # default configuration from nixos-generate-config follow
          imports =
            [ (modulesPath + "/profiles/qemu-guest.nix")
            ];

          networking.hostName = "base";
          system.stateVersion = "24.05";

          # Use the systemd-boot EFI boot loader.
          boot.loader.systemd-boot.enable = true;
          boot.loader.efi.canTouchEfiVariables = true;

          boot.initrd.availableKernelModules = [ "ahci" "xhci_pci" "virtio_pci" "sr_mod" "virtio_blk" "virtio_console" ];
          boot.initrd.kernelModules = [ ];
          boot.kernelModules = [ "kvm-intel" ];
          boot.extraModulePackages = [ ];
          boot.kernelParams = [ "console=tty0" "console=ttyS0" ];

          fileSystems."/" =
            { device = "/dev/disk/by-label/root";
              fsType = "ext4";
            };

          fileSystems."/boot" =
            { device = "/dev/disk/by-label/esp";
              fsType = "vfat";
            };

          swapDevices = [ ];

          # Enables DHCP on each ethernet and wireless interface. In case of scripted networking
          # (the default) this is the recommended approach. When using systemd-networkd it's
          # still possible to use this option, but it's recommended to use it in conjunction
          # with explicit per-interface declarations with `networking.interfaces.<interface>.useDHCP`.
          networking.useDHCP = lib.mkDefault true;
          networking.useNetworkd = true;

          nixpkgs.hostPlatform = lib.mkDefault "x86_64-linux";
        })
      ];
    }).config.system.build.vm;
  };
}
