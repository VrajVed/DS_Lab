{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    cmake
    gnumake
    gdb
  ];

  shellHook = ''
    echo "C/C++ dev environment loaded!"
    echo "GCC version: $(gcc --version | head -n1)"
    echo "CMake version: $(cmake --version | head -n1)"
  '';
}

