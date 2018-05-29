//ドラッグアンドドロップでタイルを敷くプログラム
#include <Siv3D.hpp>

void tile()
{
	constexpr int32_t TILE_SIZE = 60;
	const s3d::Array<s3d::DroppedFilePath> items = s3d::DragDrop::GetDroppedFilePaths();

	for (const auto& item : items)
	{
		s3d::Print(item.path);

		const s3d::Texture miniTexture(item.path);
		for (int32_t i = 0; i < s3d::Window::Size().x; i += TILE_SIZE)
			for (int32_t j = 0; j < s3d::Window::Size().y; j += TILE_SIZE)
				miniTexture.resized(TILE_SIZE, TILE_SIZE).draw(i, j);

	}
}

void Main()
{
	constexpr int32_t WINDOW_SIZE_X = 960;
	constexpr int32_t WINDOW_SIZE_Y = 540;

	s3d::Window::SetTitle(U"gaccho tiler");
	s3d::Window::Resize(WINDOW_SIZE_X, WINDOW_SIZE_Y);

	while (s3d::System::Update(false))
		if (s3d::DragDrop::HasNewFilePaths()) tile();

}