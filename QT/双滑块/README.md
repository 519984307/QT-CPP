# Qt-RangeSlider
Implement range slider in Qt<br>
Here is the demo:<br>
![image](https://github.com/nasafix-nasser/Qt-RangeSlider/blob/multi-type-slider/demo.gif)<br>
## How to use
1. 包含RangeSlider.h和RangeSlider.cpp到你的项目里
2. 在界面添加一个widget窗口
3. 主窗口cpp添加如下代码
	//双向滑动窗口
	RangeSlider* rangeSliderThre = new RangeSlider(Qt::Horizontal, RangeSlider::Option::DoubleHandles, nullptr);
	QHBoxLayout* rangeSliderWidgetSpaceLayout = new QHBoxLayout();
	rangeSliderWidgetSpaceLayout->addWidget(rangeSliderThre);
4. Now you can use this RangeSlider in your code.
