#include <Windows.h>
#include <xui/renderer/renderer.h>

namespace xui
{

class GdiRenderer : public Renderer
{
  public:
    GdiRenderer();
    ~GdiRenderer();

    void AttachDC(HDC hdc);
    void DetachDC();

    void DrawPoint(Point point, Color color) override;
    void DrawLine(Point from, Point to, Color color) override;
    void DrawBezierCurve(Point p0, Point p1, Point p2, Color color) override;
    void DrawCubicBezierCurve(Point p0, Point p1, Point p2, Point p3, Color color) override;
    void DrawArc(Rect bounding_rect, unsigned short from_angle, unsigned to_angle, Color color) override;
    void DrawRect(Rect rect, Color color) override;
    void DrawEllipse(Rect bounding_rect, Color color) override;
    void FillRect(Rect rect, Color color) override;
    void FillEllipse(Rect bounding_rect, Color color) override;
    void PrintText(const string &text,
                   Rect bounding_rect,
                   Color color,
                   TextAlign x_align,
                   TextAlign y_align,
                   const string &font_face,
                   unsigned short font_size,
                   bool bold,
                   bool italic,
                   bool underlined) override;
    void PrintImage(Image *image, Rect rect, Rect image_region, uint8_t alpha) override;

  private:
    HDC hdc_;
};

} // namespace xui
