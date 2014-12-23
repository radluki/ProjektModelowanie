<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Data Types" Type="Folder">
			<Item Name="Kasy.ctl" Type="VI" URL="../ModelowanieLABVIEW_copy/Kasy.ctl"/>
			<Item Name="LukiBrary.lvlib" Type="Library" URL="../ModelowanieLABVIEW_copy/LukiBrary.lvlib"/>
		</Item>
		<Item Name="new Vi&apos;s" Type="Folder">
			<Item Name="generate_population2.vi" Type="VI" URL="../ModelowanieLABVIEW_copy/generate_population2.vi"/>
			<Item Name="xxxx.vi" Type="VI" URL="../xxxx.vi"/>
		</Item>
		<Item Name="subvi&apos;s" Type="Folder">
			<Item Name="Create_population.vi" Type="VI" URL="../ModelowanieLABVIEW_copy/Create_population.vi"/>
			<Item Name="Main.vi" Type="VI" URL="../ModelowanieLABVIEW_copy/Main.vi"/>
			<Item Name="Usówanie czasów kas.vi" Type="VI" URL="../ModelowanieLABVIEW_copy/Usówanie czasów kas.vi"/>
		</Item>
		<Item Name="vi&apos;s" Type="Folder">
			<Item Name="main&apos;.vi" Type="VI" URL="../main&apos;.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_AALPro.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALPro.lvlib"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="maszyna stanowa.vi" Type="VI" URL="../ModelowanieLABVIEW_copy/maszyna stanowa.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
