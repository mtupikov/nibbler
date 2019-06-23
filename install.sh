#!/usr/bin/env bash
echo "Brew Update"
brew update
echo "Done"

echo "SFML installing.."
brew install SFML
echo "Done"

echo "SDL2 installing.."
brew install SDL2
echo "Done"

echo "SDL2 installing.."
brew install glfw
echo "Done"