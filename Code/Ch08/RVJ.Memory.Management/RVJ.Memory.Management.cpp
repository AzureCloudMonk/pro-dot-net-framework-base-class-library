// RVJ.Memory.Management.cpp : Defines the exported functions for the DLL application.
//

#ifdef __INTEL_COMPILER
#pragma warning( disable: 1079; )
#endif

#pragma region Header files
#include <Windows.Desktop.Environment.Consoles.h>
#include "RVJ.Memory.Management.h"
#pragma endregion

#pragma region Namespaces
using namespace std;
using namespace Windows::Consoles;
#pragma endregion


#pragma region Allocation function

bool Allocation( void const* newBuffer, Natural_Size sizeInBytes ) {

	bool result{};

	if ( sizeInBytes > Natural_Size( 0 ) ) {

		void* localBuffer{ ( void* )HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeInBytes ) };
		if ( ( result = GetLastError() == NO_ERROR  ) ) newBuffer = localBuffer;

	};

	return result;
};


#pragma endregion

#pragma region Relese memory function

bool Release( void const* newBuffer ) {

	bool result{ newBuffer != __nullptr };
	//OR
	//BOOL result{ newBuffer != __nullptr };

	if ( result  || ( result = HeapFree( GetProcessHeap(), {}, ( ( LPVOID ) newBuffer ) ) ) ) {

		if ( ( result = GetLastError() == NO_ERROR ) ) { /* do something. */ } 
		else { /* do something. */ };

	};

	return result;
};

#pragma endregion
