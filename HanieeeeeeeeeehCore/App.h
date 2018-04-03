#pragma once

#include "pch.h"

using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::ApplicationModel;
using namespace Windows::UI;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Core;
using namespace Platform;

namespace Hanieeeh
{

	ref class App sealed : IFrameworkView
	{
	public:
		App();

		// Inherited via IFrameworkView
		virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^applicationView);
		virtual void SetWindow(Windows::UI::Core::CoreWindow ^window);
		virtual void Load(Platform::String ^entryPoint);
		virtual void Run();
		virtual void Uninitialize();

	private:
		// App event handler
		void OnActivated(CoreApplicationView^, IActivatedEventArgs^);
		void OnResuming(Object^, Object^);
		void OnSuspending(Object^, SuspendingEventArgs^);

		// Window event handler
		void OnClick(CoreWindow^, PointerEventArgs^);
		void OnKeyDown(CoreWindow^, KeyEventArgs^);


		// Props
		bool FullScreen;
	};

	ref class AppSource sealed : IFrameworkViewSource
	{
	public:
		// Inherited via IFrameworkViewSource
		virtual IFrameworkView^ CreateView();
	};

}