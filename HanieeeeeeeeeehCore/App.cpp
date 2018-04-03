#include "pch.h"

#include "App.h"

using namespace Hanieeeh;

App::App()
{
}

void App::Initialize(CoreApplicationView ^applicationView)
{
	applicationView->Activated += ref new TypedEventHandler<CoreApplicationView ^, IActivatedEventArgs ^>(this, &App::OnActivated);
	CoreApplication::Resuming += ref new EventHandler<Object ^>(this, &App::OnResuming);
	CoreApplication::Suspending += ref new EventHandler<SuspendingEventArgs ^>(this, &App::OnSuspending);
}


void App::SetWindow(Windows::UI::Core::CoreWindow ^window)
{
	window->PointerPressed += ref new TypedEventHandler<CoreWindow^, PointerEventArgs ^>(this, &App::OnClick);
	window->KeyDown += ref new Windows::Foundation::TypedEventHandler<CoreWindow ^, KeyEventArgs ^>(this, &App::OnKeyDown);

	window->Activate();
}


void App::Load(Platform::String ^entryPoint)
{

}
void App::Run()
{
	while (true)
	{
		CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
	}
}

void App::Uninitialize()
{
	throw ref new Platform::NotImplementedException();
}

void App::OnActivated(CoreApplicationView ^, IActivatedEventArgs ^)
{
}

void App::OnResuming(Object^, Object ^)
{
}

void App::OnSuspending(Object ^, SuspendingEventArgs ^)
{
}

void App::OnClick(CoreWindow ^, PointerEventArgs^ args)
{
	auto prop = args->CurrentPoint->Position;
	auto popup = ref new MessageDialog("You cliecked on " + prop.X + " " + prop.Y, "Pointer pressed");

	popup->ShowAsync();
}

void App::OnKeyDown(CoreWindow ^, KeyEventArgs^ args)
{
}

IFrameworkView^ AppSource::CreateView()
{
	return ref new App();
}

[Platform::MTAThread]
int main(Array<String^>^ args)
{
	auto source = ref new AppSource();
	CoreApplication::Run(source);
	return 0;
}
