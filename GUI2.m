function varargout = GUI2(varargin)
% GUI2 MATLAB code for GUI2.fig
%      GUI2, by itself, creates a new GUI2 or raises the existing
%      singleton*.
%
%      H = GUI2 returns the handle to a new GUI2 or the handle to
%      the existing singleton*.
%
%      GUI2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI2.M with the given input arguments.
%
%      GUI2('Property','Value',...) creates a new GUI2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI2

% Last Modified by GUIDE v2.5 25-Nov-2014 23:54:06

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI2_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI2_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI2 is made visible.
function GUI2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI2 (see VARARGIN)

% Choose default command line output for GUI2
handles.output = hObject;
handles.y=[];% table of solutions
handles.t=[];% table of times
handles.fun=[];% table of function handles
handles.current_fun=[];
handles.transfer_fun=[];
handles.mode=1;%linear | nonlinear
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);

function [T,Y]=solve(hObject,eventdata,handles)
tmax=100;
param=get(handles.uitable1,'Data');
f = @(x) handles.current_fun(x,param);
[T,Y]=ode45(f,[0 tmax]);
handles.y=Y;
handles.t=T;
guidata(hObject,eventdata,handles);
% solves differential equation with parameters

% --- Outputs from this function are returned to the command line.
function varargout = GUI2_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1
%{
contents = cellstr(get(hObject,'String'))
value=contents{get(hObject,'Value')}
set(handles.uitable1,'Data',{2,2}')
set(handles.uitable1,'RowName',{'lal','klkl'}')
a=get(handles.uitable1,'Visible')
whos a
% nie zapominij o konwersji
if str2num(value)==1
    set(handles.uitable1,'Visible','off')
else
    set(handles.uitable1,'Visible','on')
end
guidata(hObject,handles)
%}
value=get(hObject,'Value');
if value==1
    set(handles.uitable1,'Visible','off');
    %{
    set(handles.editNumerator,'Visible','on');
    set(handles.editDenominator,'Visible','on');
    set(handles.Numerator,'Visible','on');
    set(handles.Denominator,'Visible','on');
    set(handles.Transfer,'Visible','on');
    %}
    set(handles.panelLinear,'Visible','on');
    handles.mode=1;
else
    set(handles.uitable1,'Visible','on');
    %{
    set(handles.editNumerator,'Visible','off');
    set(handles.editDenominator,'Visible','off');
    set(handles.Numerator,'Visible','off');
    set(handles.Denominator,'Visible','off');
    set(handles.Transfer,'Visible','off');
    %}
    set(handles.panelLinear,'Visible','off');
    handles.mode=2;
end
% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when entered data in editable cell(s) in uitable1.
function uitable1_CellEditCallback(hObject, eventdata, handles)
% hObject    handle to uitable1 (see GCBO)
% eventdata  structure with the following fields (see UITABLE)
%	Indices: row and column indices of the cell(s) edited
%	PreviousData: previous data for the cell(s) edited
%	EditData: string(s) entered by the user
%	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
%	Error: error string when failed to convert EditData to appropriate value for Data
% handles    structure with handles and user data (see GUIDATA)

contents = eventdata.EditData
contents = str2num(contents)
solve(hObject,eventdata,handles)





% --- Executes during object creation, after setting all properties.
function editNumerator_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editNumerator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end





% --- Executes during object creation, after setting all properties.
function editDenominator_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editDenominator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbuttonDraw.
function pushbuttonDraw_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonDraw (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


if handles.mode==1
    numerator=str2num(get(handles.editNumerator,'String'))
    denominator=str2num(get(handles.editDenominator,'String'))
    if isempty(numerator) | isempty(denominator)
        return;
    end
    handles.transfer_fun=tf(numerator,denominator);
    bode(handles.axes1,handles.transfer_fun);
    impulse(handles.axes2,handles.transfer_fun);
else
    
end
    

guidata(hObject,handles);
    
    
    
    
    
    
    
    



function editNumerator_Callback(hObject, eventdata, handles)
% hObject    handle to editNumerator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editNumerator as text
%        str2double(get(hObject,'String')) returns contents of editNumerator as a double



function editDenominator_Callback(hObject, eventdata, handles)
% hObject    handle to editDenominator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editDenominator as text
%        str2double(get(hObject,'String')) returns contents of editDenominator as a double


% --- Executes during object creation, after setting all properties.
function Denominator_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Denominator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function Numerator_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Numerator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
