//ドラッグアンドドロップでタイルを敷くプログラム
#include <Siv3D.hpp>

#define WINDOW_SIZE_X_G (960)
#define WINDOW_SIZE_Y_G (540)
#define TILE_SIZE_G (60)

void Main()
{
	Window::SetTitle(U"gaccho tiler");
	Window::Resize(WINDOW_SIZE_X_G, WINDOW_SIZE_Y_G);

	Array<s3d::DroppedFilePath> items;

	while (System::Update(false))
	{

		if (DragDrop::HasNewFilePaths())
		{
			items = DragDrop::GetDroppedFilePaths();

			for (const auto& item : items)
			{
				Print(item.path);

				Texture miniTexture(item.path);
				for (int i = 0; i < WINDOW_SIZE_X_G; i += TILE_SIZE_G) 
					for (int j = 0; j < WINDOW_SIZE_Y_G; j += TILE_SIZE_G) 
						miniTexture.resized(TILE_SIZE_G, TILE_SIZE_G).draw(i, j);

			}
		}

	}
}