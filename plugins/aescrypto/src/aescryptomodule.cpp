/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2011 Ruslan Nigmatullin <euroelessar@yandex.ru>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/
#include "aescryptomodule.h"
#include "aescryptoservice.h"

namespace AesCrypto
{

	void AesCryptoModule::init()
	{
		setInfo(QT_TRANSLATE_NOOP("Plugin", "AES crypto service loader"),
				QT_TRANSLATE_NOOP("Plugin", "Default qutIM crypto implementation. Based on algorithm aes256"),
				makePluginVersion(0, 0, 1, 0));
		addAuthor(QLatin1String("euroelessar"));
		addExtension<AesCryptoService>(QT_TRANSLATE_NOOP("Plugin", "AES crypto"),
									   QT_TRANSLATE_NOOP("Plugin", "Default qutIM crypto implementation. Based on algorithm aes256")
									   );	
	}

	bool AesCryptoModule::load()
	{
		return false;
	}

	bool AesCryptoModule::unload()
	{
		return false;
	}


}

QUTIM_EXPORT_PLUGIN(AesCrypto::AesCryptoModule)

