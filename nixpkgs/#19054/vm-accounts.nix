{ ... }: {

users.mutableUsers = false;
security.sudo.enable = true;

users.extraUsers.test = {
  description = "Test";
  isNormalUser = true;
  createHome = true;
  extraGroups = ["wheel"];
  password = "test";
};

}
