#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "TGUI Japanese Sample");
	window.setFramerateLimit(60);

	tgui::Gui gui{ window };

	// --- 日本語フォントの設定 ---
	// Windowsのフォントパスの例。ファイルが存在するか確認してください。
	// 他のOSや特定のフォントを使いたい場合は、そのパスを指定してください。
	try {
		// メイリオフォントを読み込む
		auto font = tgui::Font("C:/Windows/Fonts/msgothic.ttc"); 
		gui.setFont(font); // GUI全体に適用
	}
	catch (const tgui::Exception& e) {
		// フォントが読み込めなかった場合の処理
		std::cerr << "Font load error: " << e.what() << std::endl;
	}

	auto label = tgui::Label::create();
	// 文字列の前に「u8」を付ける（C++11以降、UTF-8リテラルとして扱う）
	label->setText(u8"こんにちは！ボタンを押してください。");
	label->setPosition(200, 100);
	label->setTextSize(24);
	gui.add(label);

	auto button = tgui::Button::create();
	button->setText(u8"クリック！");
	button->setPosition(200, 200);
	button->setSize(150, 50);
	gui.add(button);

	button->onPress([label]() {
		label->setText(u8"ボタンが押されました！");
	});

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			gui.handleEvent(*event);
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear(sf::Color(240, 240, 240));
		gui.draw();
		window.display();
	}

	return 0;
}