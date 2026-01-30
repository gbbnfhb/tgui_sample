redittでtguiのビルドの仕方を質問してる人がしたのでやってみた  
vcpkg install tguiでtguiとsfmlが入ってるとして  
c:\tgui_sample\build>cmake -G "Visual Studio 17 2022" .. -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake  
C:/dev/vcpkg/はvcpkgのある場所  
でプロジェクトを作ってビルド
  
by AI program 100%  
