#!/bin/bash

dir="./disk"
dmg="./test.dmg"

rm -rf "$dir"
mkdir "$dir"
cp -r ./Labelife/Labelife.app "$dir"
ln -s "/Applications" "$dir/Applications"
mkdir "$dir/.background"
cp "./background/installBG@2x.png" "$dir/.background"
rm -rf "$dmg"

hdiutil create "$dmg" -srcfolder "$dir" -volname "Labelife" -format UDRW

hdiutil attach "$dmg" -noverify -noautoopen -readwrite
