#ifndef _GUISLIDER_
#define _GUISLIDER_

namespace RTE {

/// <summary>
/// A slider control class.
/// </summary>
class GUISlider : public GUIControl, public GUIPanel {

public:

    // Slider orientation
    enum {
        Horizontal,
        Vertical
    } Orientation;

    // Tick Direction
    enum {
        TopLeft,
        BottomRight
    } TickDirection;

    // Slider Notifications
    enum {
        Changed = 0,
		Clicked
    } Notification;


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     GUISlider
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a GUISlider object in
//                  system memory.
// Arguments:       GUIManager, GUIControlManager.

    GUISlider(GUIManager *Manager, GUIControlManager *ControlManager);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been created.
// Arguments:       Name, Position.

    void Create(const std::string &Name, int X, int Y, int Width = -1, int Height = -1) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been created.
// Arguments:       Properties.

    void Create(GUIProperties *Props) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Destroy
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been destroyed.
// Arguments:       None.

    void Destroy() override; 


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ChangeSkin
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the skin has been changed.
// Arguments:       New skin pointer.

    void ChangeSkin(GUISkin *Skin) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Draw
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws the panel
// Arguments:       Screen class

    void Draw(GUIScreen *Screen) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:  OnMouseDown
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes down on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseDown(int X, int Y, int Buttons, int Modifier) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:  OnMouseUp
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes up on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseUp(int X, int Y, int Buttons, int Modifier) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          OnMouseMove
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse moves (over the panel, or when captured).
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseMove(int X, int Y, int Buttons, int Modifier) override;


	/// <summary>
	/// Called when the mouse scroll wheel is moved.
	/// </summary>
	/// <param name="x">Mouse X position.</param>
	/// <param name="y">Mouse Y position.</param>
	/// <param name="modifier">Activated modifier buttons.</param>
	/// <param name="mouseWheelChange">The amount of wheel movement. Positive is scroll up, negative is scroll down.</param>
	void OnMouseWheelChange(int x, int y, int modifier, int mouseWheelChange) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetPanel
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns the panel of the control.
// Arguments:       None.
// Returns:         0 if the control does not have a panel, otherwise the topmost panel.

    GUIPanel * GetPanel() override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetControlID
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns a string representing the control's ID
// Arguments:       None.

    static std::string GetControlID()    { return "SLIDER"; };


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Move
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control needs to be moved.
// Arguments:       New position.

    void Move(int X, int Y) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Resize
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control needs to be resized.
// Arguments:       New size.

    void Resize(int Width, int Height) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetControlRect
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the rectangle of the control.
// Arguments:       Position, Size.

    void GetControlRect(int *X, int *Y, int *Width, int *Height) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetOrientation
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the orientation of the slider.
// Arguments:       Orientation.

    void SetOrientation(int Orientation);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetOrientation
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the orientation of the slider.
// Arguments:       None.

    int GetOrientation() const;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetTickDirection
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the direction of the ticks.
// Arguments:       TickDir.

    void SetTickDirection(int TickDir);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetTickDirection
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the direction of the ticks.
// Arguments:       None.

    int GetTickDirection() const;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetMinimum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the minimum value.
// Arguments:       Minimum.

    void SetMinimum(int Minimum);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetMinimum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the minimum value.
// Arguments:       None.

    int GetMinimum() const;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetMaximum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the maximum value.
// Arguments:       Maximum.

    void SetMaximum(int Maximum);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetMaximum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the maximum value.
// Arguments:       None.

    int GetMaximum() const;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetValue
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the value.
// Arguments:       Value.

    void SetValue(int Value);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetValue
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the value.
// Arguments:       None.

    int GetValue() const;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          StoreProperties
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the control to store the values into properties.
// Arguments:       None.

    void StoreProperties() override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ApplyProperties
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Applies new properties to the control.
// Arguments:       GUIProperties.

    void ApplyProperties(GUIProperties *Props) override;


	/// <summary>
	/// Sets the value resolution for this slider.
	/// </summary>
	/// <param name="valueRes">The new value resolution</param>
	void SetValueResolution(int valueRes);

private:

	GUIBitmap *m_DrawBitmap;
	GUIBitmap *m_KnobImage;

	// Properties
	int m_Orientation;
	int m_TickDirection;
	int m_Minimum;
	int m_Maximum;
	int m_Value;
	int m_ValueResolution;

	// Internal variables
	int m_KnobPosition;
	int m_KnobSize;
	bool m_KnobGrabbed;
	int m_KnobGrabPos;
	int m_EndThickness;
	int m_OldValue;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          BuildBitmap
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Create the slider bitmap to draw.
// Arguments:       None.

    void BuildBitmap();


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          BuildLine
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Builds the background line for the slider
// Arguments:       Section, SrcImage.

    void BuildLine(const std::string &Section, GUIBitmap *SrcImage);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          CalculateKnob
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Calculates the knob position and size.
// Arguments:       None.

    void CalculateKnob();
};
};
#endif