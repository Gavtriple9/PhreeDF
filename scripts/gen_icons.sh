mkdir phreedf.iconset
sips -z 16 16     logo.png --out phreedf.iconset/icon_16x16.png
sips -z 32 32     logo.png --out phreedf.iconset/icon_16x16@2x.png
sips -z 32 32     logo.png --out phreedf.iconset/icon_32x32.png
sips -z 64 64     logo.png --out phreedf.iconset/icon_32x32@2x.png
sips -z 128 128   logo.png --out phreedf.iconset/icon_128x128.png
sips -z 256 256   logo.png --out phreedf.iconset/icon_128x128@2x.png
sips -z 256 256   logo.png --out phreedf.iconset/icon_256x256.png
sips -z 512 512   logo.png --out phreedf.iconset/icon_256x256@2x.png
sips -z 512 512   logo.png --out phreedf.iconset/icon_512x512.png
cp logo.png phreedf.iconset/icon_512x512@2x.png
iconutil -c icns phreedf.iconset
rm -R phreedf.iconset
mv phreedf.icns resources/